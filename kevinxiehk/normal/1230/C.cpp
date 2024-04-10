#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std; 
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
    cin>>n>>m;
    bool con[10][10];
    int cnt[10];
    for(int i=0;i<10;i++)cnt[i]=0;
    for(int i=0;i<=8;i++)for(int j=0;j<=8;j++)con[i][j]=false;
    int t,tt;
    for(int i=0;i<m;i++){
        cin>>t>>tt;
        con[t][tt]=true;
        con[tt][t]=true;
        cnt[t]++;
        cnt[tt]++;
    }
    int mi=999;
    for(int i=1;i<=7;i++)mi=min(mi,cnt[i]);
    if(mi>=1){
        int ma=0;
        for(int i=1;i<=7;i++){
            ma=1;
            t=0;
            for(int j=1;j<=7;j++){
                t=0;
                for(int k=1;k<=7;k++){
                    if(con[i][k]&&!con[j][k])t++;
                }
                ma=max(ma,t);
            }
            cnt[i]-=ma;
        }
    }
    for(int i=1;i<=7;i++)mi=min(mi,cnt[i]);
    cout<<m-mi<<endl;
	return 0;
}