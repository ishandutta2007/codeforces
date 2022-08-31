#include<bits/stdc++.h>
int a[6]={4,8,15,16,23,42};
int ans[4];
void check(){
    for(int i=0;i<4;++i)
        if(a[0]*a[i+1]!=ans[i])
            return;
    printf("! ");
    for(int i=0;i<6;++i)
        printf("%d ",a[i]);
    puts("");
    exit(0);
}
int main(){
	for(int i=0;i!=4;++i){
		printf("? %d %d\n",1,i+2);
		fflush(stdout);
		scanf("%d",&ans[i]);
	}
    do{
        check();
    }while(std::next_permutation(a,a+6));
	return 0;
}