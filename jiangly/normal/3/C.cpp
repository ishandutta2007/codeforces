#include<bits/stdc++.h>
using namespace std;
const int t[][3][2]={{{1,1},{1,2},{1,3}},{{2,1},{2,2},{2,3}},{{3,1},{3,2},{3,3}},{{1,1},{2,1},{3,1}},{{1,2},{2,2},{3,2}},{{1,3},{2,3},{3,3}},{{1,1},{2,2},{3,3}},{{1,3},{2,2},{3,1}}};
int cnta,cntb;
char s[5][5];
bool awin,bwin;
int main(){
	scanf("%s%s%s",s[1]+1,s[2]+1,s[3]+1);
	for(int i=1;i<=3;++i){
		for(int j=1;j<=3;++j){
			if(s[i][j]=='X'){
				++cnta;
			}else if(s[i][j]=='0'){
				++cntb;
			}
		}
	}
	for(int i=0;i<8;++i){
		if(s[t[i][0][0]][t[i][0][1]]=='X'&&s[t[i][1][0]][t[i][1][1]]=='X'&&s[t[i][2][0]][t[i][2][1]]=='X'){
			awin=1;
		}else if(s[t[i][0][0]][t[i][0][1]]=='0'&&s[t[i][1][0]][t[i][1][1]]=='0'&&s[t[i][2][0]][t[i][2][1]]=='0'){
			bwin=1;
		}
	}
	if(cnta<cntb||cnta>cntb+1||awin&&bwin||bwin&&cnta==4&&cntb==3||awin&&cnta==3&&cntb==3){
		printf("illegal");
	}else if(awin){
		printf("the first player won");
	}else if(bwin){
		printf("the second player won");
	}else if(cnta+cntb==9){
		printf("draw");
	}else if(cnta==cntb){
		printf("first");
	}else{
		printf("second");
	}
	return 0;
}