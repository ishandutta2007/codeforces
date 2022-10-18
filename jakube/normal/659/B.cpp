#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#define s(a) scanf("%d",&a);
#define s2(a,b) scanf("%d %d",&a,&b);
#define sc(a) cin >> a;
#define sp(b) cout << b << "\n";
#define p(a) printf("%d\n",a);
#define p2(a,b) printf("%d %d",a,b);
#define pm(a) printf("a\n");
#define test(t) while(t>0)
#define sl(a) a.length();
#define f(a,b,c) for(a=b;a<c;a++)
#define v(a,b) vector<a> b;
#define pb(a,b) a.push_back(b);
#define ll long long
#define max(a,b) (abs(a)>abs(b) ? abs(a):abs(b))
#define min(a,b) (abs(a)<abs(b) ? abs(a):abs(b))
#define diff(a,b) abs(a-b);
using namespace std;
struct datas
{
	int score;
	string name;
};
bool acompare(datas lhs,datas rhs){
	return lhs.score > rhs.score;
}

int main(){
	int t,n,m,i,j,x;
	string s;
	datas a;
	s(n);
	s(m);
	vector<datas> vec[m+1];
	
	f(i,0,n){
		cin >> s;
		s(x);
		s(t);
		a.score=t;
		a.name=s;
		vec[x].push_back(a);
	}
	f(i,1,m+1){
		sort(vec[i].begin(),vec[i].end(),acompare);
	}

	f(i,1,m+1){
	    if (vec[i].size() > 2 && vec[i][1].score == vec[i][2].score){
			printf("?\n");
		}
		else{
			cout << vec[i][0].name <<" " <<vec[i][1].name<<"\n";
		}
	}
		
}