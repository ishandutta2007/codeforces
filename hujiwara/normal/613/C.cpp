#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
  return b==0?a:gcd(b,a%b);
}

int main()
{
  int n;
  scanf("%d",&n);
  int a[30],C=0;
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
    if(a[i]%2==1){
      C++;
    }
  }
  if(C==0){
    int d=0;
    for(int i=0;i<n;i++){
      d=gcd(a[i],d);
    }
    printf("%d\n",d);
    for(int t=0;t<d/2;t++){
      for(int i=0;i<n;i++){
	for(int j=0;j<a[i]/d;j++){
	  putchar('a'+i);
	}
      }
      for(int i=n-1;i>=0;i--){
	for(int j=0;j<a[i]/d;j++){
	  putchar('a'+i);
	}
      }
    }
    putchar('\n');
  }
  else if(C==1){
    int d=0;
    for(int i=0;i<n;i++){
      d=gcd(a[i],d);
    }
    printf("%d\n",d);
    int p;
    for(int i=0;i<n;i++){
      if(a[i]%2==1){
	p=i;
	break;
      }
    }
    for(int t=0;t<d;t++){
      putchar('a'+p);
      for(int i=0;i<n;i++){
	for(int j=0;j<a[i]/d/2;j++){
	  putchar('a'+i);
	}
      }
      for(int i=n-1;i>=0;i--){
	for(int j=0;j<a[i]/d/2;j++){
	  putchar('a'+i);
	}
      }
    }
    putchar('\n');
  }
  else{
    printf("%d\n",0);
    for(int i=0;i<n;i++){
      for(int j=0;j<a[i];j++){
	putchar('a'+i);
      }
    }
    putchar('\n');
  }
  return 0;
}