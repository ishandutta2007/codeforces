#include<bits/stdc++.h>
using namespace std;

int n,m,b[2001],ans,pes;
bool k,p,sol[2001];
char a[2001][2001];

int main(){

//freopen("a.in","r",stdin);

ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>m;

for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++){
        cin>>a[i][j];
        if(a[i][j]=='1') b[j]++;
    }

    for(int i=1; i<=n; i++){
            ans=0;
            pes=0;
        for(int j=1; j<=m; j++){
            if(a[i][j]=='1'){
                pes++;
                if(b[j]>1){ ans++; }

            }

        }
        if(ans==pes){ cout<<"YES\n"; return 0; }

    }

    cout<<"NO\n";

return 0;
}