#include <bits/stdc++.h> //  l   ( 2  ) ,   3

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output1.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)


using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 1e5+5, base = 1e9+7,maxm=1e6+500;
    int ans[maxn];
    int r[maxn];
int main()
{

   // files1;
   // files2;
    fast_io;

    int n,k;
    cin>>n>>k;
    int sum = 0;
    string s,t;
    cin>>s;
    for (int i=0;i<s.size();i++){
        int a = s[i] - 'a';
        int z = 'z' - s[i];
        if (a>z){
            ans[i] = -a;
            r[i] = -1;
        }
        else{
            ans[i] = z;
            r[i] = 1;
        }
        sum += max(a,z);
    }
    t.resize(s.size());
    if (sum < k){
        puts("-1");
        return 0;
    }
    for (int i=0;i<n;i++){
        if (abs(ans[i])>k){
            t[i] = s[i];
            t[i] += r[i]*k;
           // cerr<<t<<endl;
            for (int j=i+1;j<n;j++)
                t[j] = s[j];
            cout<<t<<endl;
            return 0;
        }
        k-=abs(ans[i]);
        t[i] = s[i] + ans[i];
    }
    cout<<t;
	return 0;

}