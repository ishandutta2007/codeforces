#include <cstdio>
#include <string>
#include <vector>
using namespace std;

string ret;
char str[100005];

bool ok(string &s){
	int h = 0;
	for(auto &i : s){
		if(i == '(') h++;
		else h--;
		if(h < 0) return 0;
	}
	return h == 0;
}

int main(){
    scanf("%s",str);
    int hi = 0, cnt = 0;
    for (int i=0; str[i]; i++) {
        if(str[i] == '(') hi++;
        if(str[i] == ')' || str[i] == '#') hi--;
        if(str[i] == '#') cnt++;
        if(hi < 0){
        	puts("-1");
        	return 0;
        }
    }
    int tcnt = cnt;
    for(int i=0; str[i]; i++){
    	if(str[i] == '#'){
    		if(cnt > 1){
    			ret.push_back(')');
    		}
    		else{
    			for(int i=0; i<hi+1; i++){
    				ret.push_back(')');
    			}
    		}
    		cnt--;
    	}
    	else ret.push_back(str[i]);
    }
    if(!ok(ret)){
    	puts("-1");
    	return 0;
    }
    for (int i=0; i<tcnt-1; i++) {
        puts("1");
    }
    printf("%d",1 + hi);
}