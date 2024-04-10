#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  string st;
  int I;
  node(string s,int i){
    st=s,I=i;
  }
};

bool operator<(node n1,node n2)
{
  return n1.st.size()!=n2.st.size()?n1.st.size()>n2.st.size():n1.st>n2.st;
}

int main()
{
  string D[3][1<<8];
  vector<node> V[3];
  node nx=node("x",(16|32|64|128)),ny=node("y",(4|8|64|128)),nz=node("z",(2|8|32|128));
  V[0].push_back(nx);
  V[0].push_back(ny);
  V[0].push_back(nz);
  priority_queue<pair<node,int> > Q;
  Q.push(make_pair(nx,0));
  Q.push(make_pair(ny,0));
  Q.push(make_pair(nz,0));
  int G=0;
  while(G<(1<<8)){
    node n=Q.top().first;
    int tp=Q.top().second;
    Q.pop();
    if(D[tp][n.I]!="")continue;
    //printf("%s %d %d\n",n.st.c_str(),n.I,tp);
    D[tp][n.I]=n.st;
    if(tp==0){
      Q.push(make_pair(node('!'+n.st,((1<<8)-1)^n.I),0));
      Q.push(make_pair(n,1));
      for(int t=0;t<V[1].size();t++){
	Q.push(make_pair(node(V[1][t].st+'&'+n.st,V[1][t].I&n.I),1));
      }
    }
    else if(tp==1){
      for(int t=0;t<V[0].size();t++){
	Q.push(make_pair(node(n.st+'&'+V[0][t].st,V[0][t].I&n.I),1));
      }
      Q.push(make_pair(n,2));
      for(int t=0;t<V[2].size();t++){
	Q.push(make_pair(node(V[2][t].st+'|'+n.st,V[2][t].I|n.I),2));
      }
    }
    else if(tp==2){
      G++;
      for(int t=0;t<V[1].size();t++){
	Q.push(make_pair(node(n.st+'|'+V[1][t].st,V[1][t].I|n.I),2));
      }
      Q.push(make_pair(node('('+n.st+')',n.I),0));
    }
    V[tp].push_back(n);
  }
  int cs;
  scanf("%d",&cs);
  while(cs--){
    char s[10];
    scanf("%s",s);
    int I=0;
    for(int t=0;t<8;t++){
      if(s[t]=='1')I|=1<<t;
    }
    printf("%s\n",D[2][I].c_str());
  }
  return 0;
}