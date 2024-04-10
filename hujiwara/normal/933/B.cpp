#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long p;
  int k;
  scanf("%lld%d",&p,&k);
  set<long long> st;
  vector<int> ans;
  int q=1;
  while(p>0){
    if(st.find(p*q)!=st.end()){
      break;
    }
    st.insert(p*q);
    if(q==1){
      ans.push_back(p%k);
      p/=k;
    }
    else{
      ans.push_back(p%k==0?0:k-p%k);
      p=(p+k-1)/k;
    }
    q*=-1;
  }
  if(p==0){
    printf("%d\n",(int)ans.size());
    for(int t=0;t<ans.size();t++){
      printf("%d%c",ans[t],t==ans.size()-1?'\n':' ');
    }
  }
  else{
    puts("-1");
  }
  return 0;
}