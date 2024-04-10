#include <bits/stdc++.h>
using namespace std;

struct event
{
  int x,y,z,id;
  event(int _x,int _y,int _z,int _id){
    x=_x,y=_y,z=_z,id=_id;
  }
};

bool operator<(event e1,event e2)
{
  return e1.x!=e2.x?e1.x>e2.x:e1.id<e2.id;
}


int main()
{
  int X,Y,Z,N,M,K;
  scanf("%d%d%d%d%d%d",&X,&Y,&Z,&N,&M,&K);
  vector<int> x1(N),y1(N),z1(N);
  for(int i=0;i<N;i++){
    scanf("%d%d%d",&x1[i],&y1[i],&z1[i]);
  }
  vector<int> x2(M),y2(M),z2(M);
  for(int i=0;i<M;i++){
    scanf("%d%d%d",&x2[i],&y2[i],&z2[i]);
  }
  vector<int> x3(K),y3(K),z3(K);
  for(int i=0;i<K;i++){
    scanf("%d%d%d",&x3[i],&y3[i],&z3[i]);
  }
  int XM[2],YM[2],ZM[2];
  XM[0]=x1[0],XM[1]=x1[0];
  YM[0]=y1[0],YM[1]=y1[0];
  ZM[0]=z1[0],ZM[1]=z1[0];
  for(int i=1;i<N;i++){
    XM[0]=min(XM[0],x1[i]);
    XM[1]=max(XM[1],x1[i]);
    YM[0]=min(YM[0],y1[i]);
    YM[1]=max(YM[1],y1[i]);
    ZM[0]=min(ZM[0],z1[i]);
    ZM[1]=max(ZM[1],z1[i]);
  }
  bool COR=1;
  for(int i=0;i<M;i++){
    if(XM[0]<=x2[i]&&x2[i]<=XM[1]&&
       YM[0]<=y2[i]&&y2[i]<=YM[1]&&
       ZM[0]<=z2[i]&&z2[i]<=ZM[1]){
      COR=0;
      break;
    }
  }
  if(!COR){
    puts("INCORRECT");
    return 0;
  }
  puts("CORRECT");
  vector<bool> ans(K,false);
  for(int F=0;F<8;F++){
    int bx=F%2,by=F/2%2,bz=F/4%2;
    int dx=bx?X-XM[1]:XM[0],Dx=bx?X-XM[0]:XM[1];
    int dy=by?Y-YM[1]:YM[0],Dy=by?Y-YM[0]:YM[1];
    int dz=bz?Z-ZM[1]:ZM[0],Dz=bz?Z-ZM[0]:ZM[1];
    vector<event> es;
    for(int i=0;i<M;i++){
      int x=bx?X-x2[i]:x2[i];
      int y=by?Y-y2[i]:y2[i];
      int z=bz?Z-z2[i]:z2[i];
      if(x<=Dx&&y<=Dy&&z<=Dz){
	es.push_back(event(x<dx?x:X+1,y<dy?y:Y+1,z<dz?z:Z+1,-1));
      }
    }
    for(int i=0;i<K;i++){
      int x=bx?X-x3[i]:x3[i];
      int y=by?Y-y3[i]:y3[i];
      int z=bz?Z-z3[i]:z3[i];
      if(x<=Dx&&y<=Dy&&z<=Dz){
	es.push_back(event(x<dx?x:X+1,y<dy?y:Y+1,z<dz?z:Z+1,i));
      }
    }
    sort(es.begin(),es.end());
    set<pair<int,int> > S;
    S.clear();
    S.insert(make_pair(-1,Z+2));
    S.insert(make_pair(Y+2,-1));
    for(int t=0;t<es.size();t++){
      int x=es[t].x,y=es[t].y,z=es[t].z,id=es[t].id;
      if(id==-1){
	auto it=S.lower_bound(make_pair(y,z));
	if(it->second>=z)continue;
	it--;
	while(it->second<=z){
	  auto tit=it;
	  tit--;
	  S.erase(it);
	  it=tit;
	}
	S.insert(make_pair(y,z));
      }
      else{
	auto it=S.lower_bound(make_pair(y,z));
	if(it->second>=z){
	  ans[id]=true;
	}
      }
    }
  }
  for(int i=0;i<K;i++){
    if(XM[0]<=x3[i]&&x3[i]<=XM[1]&&
       YM[0]<=y3[i]&&y3[i]<=YM[1]&&
       ZM[0]<=z3[i]&&z3[i]<=ZM[1]){
      puts("OPEN");
    }
    else{
      puts(ans[i]?"CLOSED":"UNKNOWN");
    }
  }
  return 0;
}