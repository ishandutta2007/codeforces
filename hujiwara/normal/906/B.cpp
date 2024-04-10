#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  if(n==1){
    if(m==2||m==3){
      puts("NO");
    }
    else if(m==4){
      puts("YES");
      printf("%d %d %d %d\n",2,4,1,3);
    }
    else{
      puts("YES");
      for(int j=0;j<m;j++){
	printf("%d%c",j%2==0?j/2+1:j/2+(m+1)/2+1,j==m-1?'\n':' ');
      }
    }
  }
  else if(m==1){
    if(n==2||n==3){
      puts("NO");
    }
    else if(n==4){
      puts("YES");
      printf("%d\n%d\n%d\n%d\n",2,4,1,3);
    }
    else{
      puts("YES");
      for(int i=0;i<n;i++){
	printf("%d\n",i%2==0?i/2+1:i/2+(n+1)/2+1);
      }
    }
  }
  else if(m>=4){
    puts("YES");
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	int y=(i%2==0?j:(j+2)%m);
	int x=(y%2==0?i:(i+1)%n);
	printf("%d%c",x*m+y+1,j==m-1?'\n':' ');
      }
    }
  }
  else if(n>=4){
    puts("YES");
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	int x=(j%2==0?i:(i+2)%n);
	int y=(x%2==0?j:(j+1)%m);
	printf("%d%c",x*m+y+1,j==m-1?'\n':' ');
      }
    }
  }
  else if(n==3&&m==3){
    puts("YES");
    printf("%d %d %d\n%d %d %d\n%d %d %d\n",1,3,4,5,7,6,9,2,8);
  }
  /*int b[9];
    for(int i=0;i<9;i++)b[i]=i;
    do{
      bool F=0;
      for(int x=0;x<9;x++){
	for(int y=0;y<9;y++){
	  int X=b[x],Y=b[y];
	  if(((x%3==y%3&&abs(x/3-y/3)==1)||(x/3==y/3&&(abs(x%3-y%3)==1)))&&
	     ((X%3==Y%3&&abs(X/3-Y/3)==1)||(X/3==Y/3&&(abs(X%3-Y%3)==1)))){
	    F=1;
	  }
	}
      }
      if(!F){
	for(int i=0;i<9;i++){
	  printf("%d\n",b[i]+1);
	}
	break;
      }
    }while(next_permutation(b,b+9));
    }*/
  else{
    puts("NO");
  }
  return 0;
}