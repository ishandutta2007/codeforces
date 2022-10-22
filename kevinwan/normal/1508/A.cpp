#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
const int mn=120+10;
string s[3];
int num[3],mr[3];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        cin>>s[0]>>s[1]>>s[2];
        memset(num,0,sizeof(num));
        memset(mr,0,sizeof(mr));
        for(int i=0;i<3;i++){
            for(int j=0;j<n*2;j++)num[i]+=(s[i][j]-='0');
            mr[i]=(num[i]>n);
        }
        int m=(mr[0]+mr[1]+mr[2]>=2);
        string a,b;
        for(int i=0;i<3;i++){
            if(mr[i]==m)b=a,a=s[i];
        }
        int aa=0,bb=0;
        for(int i=0;i<2*n;i++){
            aa+=(a[i]==m);
            bb+=(b[i]==m);
        }
        vi v(max(aa,bb)+1);
        for(int i=0,j=0,st=-1;i<2*n;i++){
            if(a[i]==m)j++,st=i;
            else{
                v[j]=max(v[j],i-st);
            }
        }
        for(int i=0,j=0,st=-1;i<2*n;i++){
            if(b[i]==m)j++,st=i;
            else{
                v[j]=max(v[j],i-st);
            }
        }
        for(int i=0;i<v.size();i++){
            if(i)printf("%d",m);
            for(int j=0;j<v[i];j++)printf("%d",m^1);
        }
        printf("\n");
    }
}