#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))	c = getchar();
	while(isdigit(c))	a += (a << 3) + a + (c ^ '0') , c = getchar();
	return a;
}
map < int , int > m;
struct p{
	int a , b , i;
}ans[200001];
bool cmp(p a , p b){
	return a.a > b.a || a.a == b.a && a.b > b.b;
}
int main(){
	for(int N = read() ; N ; N--)	m[read()]++;
	int N = read();
	for(int i = 0 ; i < N ; i++){
		ans[i].i = i + 1;
		ans[i].a = m.find(read())->second;
	}
	for(int i = 0 ; i < N ; i++)
		ans[i].b = m.find(read())->second;
	sort(ans , ans + N , cmp);
	cout << ans[0].i;
	return 0;
}