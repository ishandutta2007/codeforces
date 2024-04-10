//Problem D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;
int n;
ll h,l[N],r[N],len[N],Ans;

int main(){
    cin>>n>>h;
    for(int i=1;i<=n;i++)cin>>r[i-1]>>l[i];
    for(int i=1;i<=n;i++)len[i]=len[i-1]+r[i]-l[i];
    for(int i=1;i<=n;i++){
        int lll=i,rrr=n,ans=i;
        while(lll<=rrr){
            int mid=(lll+rrr)>>1;
            if(len[mid-1]-len[i-1]<h)ans=mid,lll=mid+1;
            else rrr=mid-1;
        }
        Ans=max(Ans,l[ans]+h-(len[ans-1]-len[i-1])-r[i-1]);
    }
    cout<<Ans;
    return 0;
}