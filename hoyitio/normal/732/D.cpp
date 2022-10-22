#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 1e5+10;
int Subject[MAXN];
int Day[MAXN];
bool visit[MAXN];
int n,m;
bool judge(int ND)
{
    if(ND == 0||ND>n)return false;
    memset(visit,0,sizeof(visit));
    int D = ND;
    int cnt = 0;
    int temp = 0;
    for(int i = ND; i >= 1; i--)
    {
        int k = Subject[i];
        //cout<<"k = "<<k<<endl;
        if(k==0){
            if(temp){temp--;}
            else{D--;}
            continue;
        }
        if(!visit[k])
        {
            visit[k]=1;
            cnt++;
            D--;
            D-=Day[k];
            temp+=Day[k];
            if(D<0){return false;}
        }
        else{
            if(temp){temp--;}
            else{D--;}
        }
    }
    if(cnt!=m){
        return false;
    }
    return true;
}
int Binary()
{
    int R = n,L = 1;
    while( L <= R) {
        //cout<<"L = "<<L<<" R = "<<R<<endl;
       int mid = L+(R-L)/2;
       if(!judge(mid)) {L = mid + 1;} //
       else {
           if(!judge(mid-1)){return mid;}
            R = mid - 1;
       } //
    }
    return -1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ;i++)
    {
        scanf("%d",&Subject[i]);
    }
    for(int j = 1 ; j <= m ; j++)
    {
        scanf("%d",&Day[j]);
    }
    int ans = Binary();
    printf("%d\n",ans);
    return 0;
}