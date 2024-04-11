#include <cstdio>

char t1[25], t2[25];
int n;

int ycnt[255][105];

int main(){
	scanf("%s %s",t2,t1);
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int foultime;
		char str[11];
		int num;
		char str2[11];
		scanf("%d %s %d %s",&foultime, str, &num, str2);
		if(str2[0] == 'r'){
			if(ycnt[str[0]][num] >= 2){
				continue;
			}
			if(str[0] =='a'){
				printf("%s %d %d\n",t1, num, foultime);
			}
			else{
				printf("%s %d %d\n",t2,num,foultime);
			}
			ycnt[str[0]][num] = 1e9;
		}
		else{
			ycnt[str[0]][num]++;
			if(ycnt[str[0]][num] == 2){
				if(str[0] =='a'){
					printf("%s %d %d\n",t1, num, foultime);
				}
				else{
					printf("%s %d %d\n",t2,num,foultime);
				}
			}
		}
	}
}