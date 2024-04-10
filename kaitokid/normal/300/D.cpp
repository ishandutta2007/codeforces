#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1 << 20;
int pw(int x,int y)
{
    int res=1;
    while(y>0)
    {
        if(y&1)res=(res*1LL*x)%mod;
        y/=2;
        x=(x*1LL*x)%mod;
    }
    return res;
}
int inverse(int x,int md)
{
    return pw(x,md-2);
}
void fft(vector<int> & a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = inverse(n, mod);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}
vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] = (fa[i]*1LL*fb[i])%mod;
    fft(fa, true);

    return fa;
}
vector<int>ans[40];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   ans[0].push_back(1);
   for(int i=0;i<1000;i++)ans[0].push_back(0);
   for(int i=1;i<35;i++)
   {
       vector<int>g=multiply(ans[i-1],ans[i-1]);
       g=multiply(g,g);
       ans[i].push_back(1);
       for(int j=0;j<1000;j++)ans[i].push_back(g[j]);

   }
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int r=0;
        while(n>1 && n%2 ==1)r++,n/=2;
        cout<<ans[r][k]<<endl;
    }

    return 0;
}