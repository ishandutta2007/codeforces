#include <iostream>

using namespace std;

int que[100005][2],r=0;
int main()
{
    int n,s,q,p;
    char d;
    long long sell[100005],buy[100005];
    for(int i=0;i<100005;i++){
        sell[i]=0;
        buy[i]=0;
    }

    cin>>n>>s;
    int ks=0,kb=0,maxs=0,maxb=0;
    for (int i=0;i<n;i++){
        cin>>d>>p>>q;
        if (d=='S'){
            sell[p]+=(long long)q;
            if (p>maxs)maxs=p;
            ks++;
        } else
        {
            buy[p]+=(long long)q;
            if (p>maxb)maxb=p;
            kb++;
        }
    }


    int ts=0,tb=0;
    for (int i=0;i<=maxs;i++){
        if (sell[i]>0){
            que[r][1]=sell[i];
            que[r][2]=i;
            r++;
            ts++;
        }
        if (ts==s) break;
    }
    r--;
   for (int i=r;i>=0;i--){
    cout<<"S "<<que[i][2]<<" "<<que[i][1]<<endl;
   }
    for (int i=maxb+1;i>=0;i--){
        if (buy[i]>0){
            cout<<"B "<<i<<" "<<buy[i]<<endl;
            tb++;
        }
        if (tb==s) break;
    }
    return 0;
}