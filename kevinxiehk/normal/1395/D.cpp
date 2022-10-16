#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
bool cmp(int a,int b){return a>b;}
main(){
    int n,d,m;
    cin>>n>>d>>m;
    int arr[n+5];
    int t;
    int highcnt=0,normcnt=0;
    int high[n+5],norm[n+5];
    high[0]=0;norm[0]=0;
    for(int i=0;i<n;i++){
        cin>>t;
        if(t>m){
            high[highcnt+1]=t;
            highcnt++;
        }
        else{
            norm[normcnt+1]=t;
            normcnt++;
        }
    }
    sort(high+1,high+highcnt+1,cmp);
    sort(norm+1,norm+normcnt+1,cmp);
    for(int i=1;i<=highcnt+1;i++){high[i]+=high[i-1];}
    //cout<<endl;
    for(int i=1;i<=normcnt+1;i++){norm[i]+=norm[i-1];}
    //cout<<endl;
    int ans=0;
    for(int i=1;i<=n;i+=(d+1)){
        int a=(i/(d+1))+1;
        int b=n-i;
        a=min(a,highcnt);
        b=min(b,normcnt);
        if(a*(d+1)+b<n)continue;
        //if(high[a]+norm[b]>ans)cout<<a<<" "<<b<<" "<<high[a]+norm[b]<<endl;
        ans=max(ans,high[a]+norm[b]);
    }
    if(highcnt==0){
        ans=norm[normcnt];
    }
    cout<<ans<<endl;
    // int ans[n+d+10][2];
    // for(int i=0;i<=n+d+5;i++)ans[i][0]=0,ans[i][1]=0;
    // int a,b,c;
    // for(int i=n-1;i>=0;i--){
    //     a=0,b=0,c=0;
    //     if(ans[i+d+1][0]<highcnt){
    //         a=high[ans[i+d+1][0]+1]+norm[ans[i+d+1][1]];
    //     }
    //     if(ans[i+1][1]<normcnt){
    //         b=norm[ans[i+1][1]+1]+high[ans[i+1][0]];
    //     }
    //     c=norm[ans[i+1][1]]+high[ans[i+1][0]];
    //     if(a>b&&a>c){
    //         ans[i][0]=ans[i+d+1][0]+1;
    //         ans[i][1]=ans[i+d+1][1];
    //     }
    //     else if(b>c){
    //         ans[i][0]=ans[i+1][0];
    //         ans[i][1]=ans[i+1][1]+1;
    //     }
    //     else{
    //         ans[i][0]=ans[i+1][0];
    //         ans[i][1]=ans[i+1][1];
    //     }
    // }
    // cout<<ans[0][0]<<" "<<ans[0][1]<<endl;
    // cout<<high[ans[0][0]]+norm[ans[0][1]]<<endl;
    return 0;
}