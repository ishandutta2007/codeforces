#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 100005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,A[N],op,a;
std::multiset<int>S1,S2;
std::multiset<int>::iterator it1,it2,it3;
void add(int v)
{
	S1.insert(v);
	if(S1.size()==1) return;
	it1=S1.find(v);
	if(it1==S1.begin()) {it1++,S2.insert((*it1)-v);return;}
	it2=it1,it2++,it1--,S2.insert(v-(*it1));
	if(it2==S1.end()) return;
	S2.insert((*it2)-v);
	it3=S2.find((*it2)-(*it1)),S2.erase(it3);
}
void Delete(int v)
{
	it1=S1.find(v);
	if(S1.size()==1) {S1.erase(v);return;}
	if(it1==S1.begin()) {it1++,it3=S2.find((*it1)-v),S2.erase(it3),S1.erase(v);return;}
	it2=it1,it2++,it1--;
	it3=S2.find(v-(*it1)),S2.erase(it3);
	if(it2==S1.end()) {S1.erase(v);return;}
	it3=S2.find((*it2)-v),S2.erase(it3);
	S2.insert((*it2)-(*it1)),S1.erase(v);
}
void Solve()
{
	if(S1.size()<3) return void(puts("0"));
	it1=S1.end(),it1--,it2=S2.end(),it2--;
	printf("%d\n",(*it1)-(*S1.begin())-(*it2));
}
void debug()
{
	for(it1=S1.begin();it1!=S1.end();it1++) dbg1((*it1));puts("");
	for(it2=S2.begin();it2!=S2.end();it2++) dbg1((*it2));puts("");
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]),add(A[i]);
	for(Solve();m--;Solve())
	{
		scanf("%d%d",&op,&a);
		if(op) add(a);else Delete(a);
		// debug();
	}
	return 0;
}