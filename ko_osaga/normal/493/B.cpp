#include <cstdio>
#include <vector>
using namespace std;

vector<int> v1, v2;
long long s;
int n;

int main(){
	scanf("%d",&n);
	int last;
	for(int i=0; i<n; i++){
		int t;
		scanf("%d",&t);
		if(t > 0) v1.push_back(t);
		else v2.push_back(-t);
		s += t;
		last = t;
	}
	while(v1.size() < v2.size()){
		v1.push_back(-1e9);
	}
	while(v2.size() < v1.size()){
		v2.push_back(-1e9);
	}
	if(s > 0){
		puts("first");
	}
	else if(s < 0){
		puts("second");
	}

	else{
		for(int i=0; i<v1.size(); i++){
			if(v1[i] != v2[i]){
				if(v1[i] > v2[i]){
					puts("first");
					return 0;
				}
			else{
				puts("second");
				return 0;
			}
			}
		}
	if(last > 0){
		puts("first");
	}
	else{
		puts("second");
	}
	}
}