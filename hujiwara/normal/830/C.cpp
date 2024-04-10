#include <bits/stdc++.h>
using namespace std;

const long long INF=1000000000000ll;

const int X=60000;

int main()
{
  int n;
  long long K;
  scanf("%d%lld",&n,&K);
  vector<long long> a(n);
  for(int i=0;i<n;i++){
    scanf("%lld",&(a[i]));
  }
  priority_queue<pair<long long,int > > Q;
  long long D=INF,S=0;
  for(int i=0;i<n;i++){
    Q.push(make_pair(a[i],i));
    S+=D-a[i];
  }
  vector<int> p(n,1);
  int L=n;
  long long ans=-1;
  while(D>=X){
    pair<long long,int> P=Q.top();
    Q.pop();
    long long D2=P.first;
    int id=P.second;
    long long S2=S-(D-D2)*L;
    //printf("%lld %lld\n",D2,S2);
    if(S2<=K){
      ans=D2+(K-S2)/L;
      break;
    }
    p[id]++;
    L++;
    Q.push(make_pair((a[id]+p[id]-1)/p[id],id));
    D=D2;
    S=S2+D2;
  }
  if(ans==-1){
    while(1){
      D--;
      long long S=0;
      for(int i=0;i<n;i++){
	S+=(D-a[i]%D)%D;
      }
      if(S<=K){
	ans=D;
	break;
      }
    }
  }
  printf("%lld\n",ans);
  return 0;
}