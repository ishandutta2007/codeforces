#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
struct p{ll x[3],i;}po[8];
p operator-(const p&a,const p&b){
                  p t;
                  for (int i=0;i<3;i++)t.x[i]=a.x[i]-b.x[i];
                  return t;
}
p operator+(const p&a,const p&b){
                  p t;
                  for (int i=0;i<3;i++)t.x[i]=a.x[i]+b.x[i];
                  return t;
}
ll operator*(const p&a,const p&b){
                  ll ans=0;
                  for (int i=0;i<3;i++)ans+=1ll*a.x[i]*b.x[i];
                  return ans;
}
int cmp(const p&a,const p&b){
    for (int i=0;i<3;i++){
        if(a.x[i]!=b.x[i])return a.x[i]<b.x[i];
    }
    return 0;
}
ll det(ll a,ll b,ll c,ll d){
          return a*d-b*c;
}
p operator^(const p&a,const p&b){
                  p t;
                  t.x[0]=det(a.x[1],a.x[2],b.x[1],b.x[2]);
                  t.x[1]=det(b.x[0],b.x[2],a.x[0],a.x[2]);
                  t.x[2]=det(a.x[0],a.x[1],b.x[0],b.x[1]);
                  return t;
}
                  
ll dissq(const p&a,const p&b){
               ll ans=0;
               for (int i=0;i<3;i++)ans+=1ll*(a.x[i]-b.x[i])*(a.x[i]-b.x[i]);
               return ans;
}
p bas[4],lef[4];
p ba[4];
ll dq;ll d;
p up[4],tmup[4];
int check(){
    for (int i=0;i<4;i++)ba[i]=bas[i];
    for (int i=1;i<4;i++)
        if(dissq(ba[i],ba[0])>dissq(ba[2],ba[0]))swap(ba[i],ba[2]);
    ll di[4];
    di[0]=dissq(ba[0],ba[1]);
    di[1]=dissq(ba[1],ba[2]);
    di[2]=dissq(ba[2],ba[3]);
    di[3]=dissq(ba[3],ba[0]);
    if(di[0]==di[1] && di[1]==di[2] && di[2]==di[3]){
                    dq=di[0];
                    d=ll(0.5+sqrt(dq));
                    if(d*d!=dq)return 0;
                    if(!d)return 0;
                    if((ba[2]-ba[1])*(ba[1]-ba[0])==0 && (ba[2]-ba[1])*(ba[3]-ba[2])==0
                    && (ba[0]-ba[3])*(ba[3]-ba[2])==0&& (ba[1]-ba[0])*(ba[0]-ba[3])==0)return 1;
                    else return 0;                    
    }else return 0;
}

int equal(){
    for (int i=0;i<4;i++){
        tmup[i]=up[i];
        sort(tmup[i].x,tmup[i].x+3);
        }
    sort(tmup,tmup+4,cmp);
    for (int i=0;i<4;i++)if(cmp(tmup[i],lef[i])||cmp(lef[i],tmup[i]))return 0;
    int mark[4]={0};
    for (int i=0;i<4;i++){
        p tt=up[i];
        sort(tt.x,tt.x+3);
        for (int j=0;j<4;j++)if(!mark[j] && !(cmp(tt,lef[j])||cmp(lef[j],tt))){
            mark[j]=1,up[i].i=lef[j].i;break;
            }
    }
    return 1;
}
int combine1(){
    up[0]=(ba[1]-ba[0])^(ba[3]-ba[0]);
    up[1]=(ba[2]-ba[1])^(ba[0]-ba[1]);
    up[2]=(ba[3]-ba[2])^(ba[1]-ba[2]);
    up[3]=(ba[0]-ba[3])^(ba[2]-ba[3]);    
    for (int i=0;i<4;i++){
        for (int j=0;j<3;j++){
            if(up[i].x[j]%d)return 0;
            up[i].x[j]/=d;
            }
    }
    for (int i=0;i<4;i++)up[i]=up[i]+ba[i];
    if(equal())return 1;
    else return 0;
}
int combine2(){
    up[0]=(ba[3]-ba[0])^(ba[1]-ba[0]);
    up[1]=(ba[0]-ba[1])^(ba[2]-ba[1]);
    up[2]=(ba[1]-ba[2])^(ba[3]-ba[2]);
    up[3]=(ba[2]-ba[3])^(ba[0]-ba[3]);    
    for (int i=0;i<4;i++){
        for (int j=0;j<3;j++){
            if(up[i].x[j]%d)return 0;
            up[i].x[j]/=d;
            }
    }
    for (int i=0;i<4;i++)up[i]=up[i]+ba[i];
    if(equal()){
                return 1;
    }    else return 0;
}
int dfs(int i){
    if(i==4){
             if(check()){
                         if(combine1())return 1;
                         else if(combine2())return 1;
                         else return 0;
             }else return 0;
    }else{
          do{
                   if(dfs(i+1))return 1;
          }while(next_permutation(bas[i].x,bas[i].x+3));
    }
    return 0;
}
p ans[8];
int main()
{
    for (int i=0;i<8;i++){
        cin>>po[i].x[0]>>po[i].x[1]>>po[i].x[2];po[i].i=i;
        sort(po[i].x,po[i].x+3);
    }
    for (int i=0;i<256;i++){
        int cnt=0;for (int j=0;j<8;j++)if(1<<j&i)cnt++;
        if(cnt==4){
                   cnt=0;int cnt2=0;
                   for (int j=0;j<8;j++)
                       if(1<<j&i)bas[cnt++]=po[j];
                       else lef[cnt2++]=po[j];
                   sort(lef,lef+4,cmp);
                   if(dfs(0)){
                              for (int i=0;i<4;i++)ans[i]=ba[i];
                              for (int i=0;i<4;i++)ans[i+4]=up[i];
                              printf("YES\n");
                              for (int i=0;i<8;i++)
                                  for (int j=0;j<8;j++)if(ans[j].i==i)cout<<ans[j].x[0]<<" "<<ans[j].x[1]<<" "<<ans[j].x[2]<<endl;
                              return 0;          
                   }
        }
    }
    printf("NO\n");
    return 0;
}