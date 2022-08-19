#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

char str[200005];
int n;

int main(){
	scanf("%d %s",&n,str);
	printf("%d",abs(count(str,str+n,'0') - count(str,str+n,'1')));
}