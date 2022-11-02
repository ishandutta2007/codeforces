#include<cstdio>
#include<algorithm>
using namespace std;
int n,num,maxcnt,cnt[100005],minidx[100005],maxidx[100005];
int ansa,ansb=0x7fffffff;
struct element{
    int idx,val;
}arr[100005];
bool comp(element A,element B){return A.val<B.val;}

int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        scanf("%d",&arr[i].val);
        arr[i].idx=i;
    }
    sort(arr+1,arr+n+1,comp);
    for(i=1;i<=n;i++) {
        if(arr[i].val!=arr[i-1].val) {
            num++;
            minidx[num]=0x7fffffff;
        }
        cnt[num]++;
        maxcnt=max(maxcnt,cnt[num]);
        minidx[num]=min(minidx[num],arr[i].idx);
        maxidx[num]=max(maxidx[num],arr[i].idx);
    }
    for(i=1;i<=num;i++) {
        if(cnt[i]==maxcnt) {
            if(maxidx[i]-minidx[i]<ansb-ansa) {
                ansa=minidx[i];
                ansb=maxidx[i];
            }
        }
    }
    printf("%d %d",ansa,ansb);
}