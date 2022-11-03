#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int m[8]={1,1,1,1,1,1,1,1};
	cin >> n;
	char c;
	for(int i=0;i<n;i++){
		c = '\n';
		while(c=='\n'){
			cin >> c;
		}
		switch(c){
		case '1':case'2':case '3':m[0]=0;
		}
		switch(c){
		case '1':case'4':case '7':case'0':m[1]=0;
		}
		switch(c){
		case '3':case'6':case '9':case'0':m[2]=0;
		}
		switch(c){
		case '7':case'9':case '0':m[3]=0;
		}
		switch(c){
		case '1':case'2':case '3':case'6':case'9':m[4]=0;
		}
		switch(c){
		case '1':case'2':case '3':case'4':case'7':m[5]=0;
		}
		switch(c){
		case '1':case'4':case '7':case'8':case'0':m[6]=0;
		}
		switch(c){
		case '3':case'6':case '9':case'8':case'0':m[7]=0;
		}
	}
	for(int i=0;i<8;i++){
		if(m[i]==1){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}