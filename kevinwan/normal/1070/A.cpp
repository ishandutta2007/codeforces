#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int dis[500][5001],bn[500][5001];
pii bac[500][5001];
int main(){
    int s,d,i;
    scanf("%d%d",&d,&s);
    memset(dis,-1,sizeof(dis));
    queue<pii>q;
    q.push({0,0});
    dis[0][0]=0;
    while(q.size()){
        pii p=q.front();
        q.pop();
        for(i=0;i<=9;i++){
            if(p.second+i>s)continue;
            pii pp={(p.first*10+i)%d,p.second+i};
            if(dis[pp.first][pp.second]==-1){
                dis[pp.first][pp.second]=dis[p.first][p.second]+1;
                bac[pp.first][pp.second]=p;
                bn[pp.first][pp.second]=i;
                q.push({pp});
            }
        }
    }
    if(dis[0][s]==-1)printf("-1");
    else{
        pii p={0,s};
        string s;
        while(p.first||p.second){
            s.push_back(bn[p.first][p.second]+'0');
            p=bac[p.first][p.second];
        }
        reverse(s.begin(),s.end());
        printf("%s",s.c_str());
    }
}