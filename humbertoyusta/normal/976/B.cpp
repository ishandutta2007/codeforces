#include<bits/stdc++.h>
#define maxn 1005
#define mod 1000000007
using namespace std;

long long n,m,k,pos,sec,sit,r,c;

int main(){

ios_base::sync_with_stdio(0);
cin.tie(0);

///freopen("a.in","r",stdin);

    cin>>n>>m>>k;


    if(k+1<=n){ cout<<k+1<<" 1\n"; return 0; }
    if(k+1<n+m){ cout<<n<<' '<<k-n+2; return 0; }

    pos=k+1-(n+m);

    r = n - (pos) / (m-1) - 1;

    cout<<r<<' ';

    if(r&1){
        c = m - pos % ( m - 1 );
    }
        else{
            c= 2 + pos % ( m - 1 );
        }

    cout<<c<<'\n';

return 0;
}