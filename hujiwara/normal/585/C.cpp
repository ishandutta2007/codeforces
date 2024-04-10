#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long x,y;
  scanf("%lld%lld",&x,&y);
  ostringstream ans;
  bool F;
  while(1){
    if(x<=y){
      if(y%x==0){
	if(x>1){
	  F=0;
	}
	else{
	  F=1;
	  ans<<y-1<<'B';
	}
	break;
      }
      else{
	ans<<y/x<<'B';
	y%=x;
      }
    }
    else{
      if(x%y==0){
	if(y>1){
	  F=0;
	}
	else{
	  F=1;
	  ans<<x-1<<'A';
	}
	break;
      }
      else{
	ans<<x/y<<'A';
	x%=y;
      }
    }
  }
  if(F){
    printf("%s\n",ans.str().c_str());
  }
  else{
    puts("Impossible");
  }
  return 0;
}