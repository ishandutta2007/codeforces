#include <stdio.h>
#include <queue>

using namespace std;

struct mindol{int val;bool operator<(const mindol &a)const{return (10-(val%10))>(10-(a.val%10));}};

priority_queue<mindol> pq;

int n,k,a[101010],ans;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    for(int i=0;i<n;i++)pq.push({a[i]});
    int cur;
    while(!pq.empty() && k){
        cur=pq.top().val;
        pq.pop();
        if(cur==100){ans+=10;continue;}
        if(10-(cur%10)>k)cur+=k,k=0;
        else k-=(10-(cur%10)),cur+=(10-(cur%10));
        if(cur==100)ans+=10;
        else pq.push({cur});
    }
    while(!pq.empty()){
        ans+=pq.top().val/10;
        pq.pop();
    }
    printf("%d",ans);
}