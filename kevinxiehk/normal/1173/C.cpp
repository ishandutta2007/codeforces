#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std; 
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
    cin>>n;
    int arr[n+5],oof[n+5],index[n+5];
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++)cin>>oof[i];
    for(int i=1;i<=n;i++)index[i]=-1;
    for(int i=1;i<=n;i++)index[oof[i]]=i;
    int last=oof[n];
    int llast=last;
    sort(arr+1,arr+n+1);
    bool onhand[n+5];
    for(int i=0;i<=n+2;i++)onhand[i]=false;
    for(int i=1;i<=n;i++){
        if(arr[i]!=0)onhand[arr[i]]=true;
    }
    int cando=true;
    while(llast>0){
        if(oof[n-(last-llast)]==llast)llast--;
        else{
            cando=false;
            break;
        }
    }
    if(cando){
        for(int i=last+1;i<=n;i++){
            int t=i-last;
            t--;
            if(index[i]<=t)continue;
            else cando=false;
        }
    }
    if(cando)cout<<(n-last)<<endl;
    else{
        int aaa=0;
        int t=0;
        for(int i=1;i<=n;i++){
            if(oof[i]==0)continue;
            t=i-(oof[i]-1);
            aaa=max(aaa,t);
        }
        cout<<(aaa+n)<<endl;
    }
	return 0;
}