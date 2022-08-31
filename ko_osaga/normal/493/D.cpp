#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> pi;

vector<pi> v;

int main(){
	int n;
	scanf("%d",&n);
	puts(n%2 ? "black" : "white");
	if(n%2 == 0){
		printf("1 2");
	}
}