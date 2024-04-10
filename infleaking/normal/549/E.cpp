#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
unsigned rand(unsigned x){
	return (rand()*RAND_MAX+rand())%x;
}
using namespace std;
typedef long double ld;
typedef long long ll;
const ld eps=1e-9;
const int N=1e4+10;
struct dot{int x,y;};
struct dot2{ld x,y;};
struct line{dot u,v;};
dot operator-(dot a,dot b){return (dot){a.x-b.x,a.y-b.y};}
dot2 operator-(dot2 a,dot b){return (dot2){a.x-b.x,a.y-b.y};}
dot operator+(dot a,dot b){return (dot){a.x+b.x,a.y+b.y};}
dot2 operator+(dot a,dot2 b){return (dot2){a.x+b.x,a.y+b.y};}
dot2 operator*(dot a,ld x){return (dot2){a.x*x,a.y*x};}
ll cross(dot a,dot b){
	return ((ll)a.x*b.y-a.y*b.x);
}
ld cross(dot a,dot2 b){
	return (a.x*b.y-a.y*b.x);
}
ld cross0(line a,line b){
	return (ld)cross(b.u-a.u,b.v)/cross(a.v,b.v);
}
typedef vector<dot> vec;
vector<dot> a,b,c,a1;
int n,m;
dot ST;
bool comp(dot a,dot b){
	int z=cross(a-ST,b-ST);
	if (z==0)return a.y<b.y;
	return z>0;
}
bool comp2(dot a,dot b){
	if (a.y==b.y)return a.x<b.x;
	return a.y>b.y;
}
vec rebuild(vec a){
	sort(a.begin(),a.end(),comp2);
	ST=a.back();a.pop_back();
	sort(a.begin(),a.end(),comp);
	vec c;c.clear();
	c.push_back(ST);
	c.push_back(a[0]);
	for (int i=1;i<a.size();i++){
		while (c.size()>2&&cross(a[i]-c.back(),(*----c.end())-c.back())<=0)
			c.pop_back();
		c.push_back(a[i]);
	}
	return c;
}
vector<line> h;
dot2 z1,z2;
ll dot1(dot a,dot b){
	return (ll)a.x*b.x+a.y*b.y;
}
line Mid(dot a,dot b){
	return (line){(dot){a.x+b.x>>1,a.y+b.y>>1},(dot){a.y-b.y,b.x-a.x}};
}
int push(int i0,int j0){
	line a=Mid(c[j0],a1[i0]);
//	cout<<a.u.x<<' '<<a.u.y<<' '<<a.v.x+a.u.x<<' '<<a.v.y+a.u.y<<endl;
	if (cross(a.v,z2-a.u)<eps||h.empty()){
		ld mx=1e9,mn=-1e9;
		for (int i=0;i<a1.size();i++){
		for (int j=0;j<c.size();j++){
			if (i==i0&&j==j0)break;
			line h0=Mid(c[j],a1[i]);
			if (cross(a.v,h0.v)==0){
				if (dot1(a.v,h0.v)<0){
					if (cross(h0.u-a.u,a.v)>=0){
						return -1;
					}
				}
				continue;
			}
			ld q=cross0(a,h0);
			if (cross(a.v,h0.v)>0) mx=min(mx,q);
			else mn=max(mn,q);
		}
		if (i==i0)break;
		}
		if (mx<mn+eps)return 1;
		if (cross(a.v,z1))z2=a.u+a.v*mn;
		else z2=a.u+a.v*mx;
		if (h.empty())h.push_back(a);
		return 0;
	}
	else {
		if (h.empty())h.push_back(a);
		return 0;
	}
}
void random_s(vec &a){
	for (int i=1;i<a.size();i++)
		swap(a[i],a[rand(i+1)]);
}
int main(){
	cin>>n>>m;
	a.resize(n);
	b.resize(m);
	for (int i=0;i<n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].x*=2,a[i].y*=2;
	}
	for (int i=0;i<m;i++){
		scanf("%d%d",&b[i].x,&b[i].y);
		b[i].x*=2,b[i].y*=2;
	}
	c=rebuild(b);
	a1=a;
	random_s(c);
	random_s(a1);
	z1=(dot2){0.4415926535,2.718281828};
	int fail=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<c.size();j++){
			if (push(i,j)){
				fail=1;
				break;
			}
		}
		if (fail)break;
	}
	if (!fail){
		cout<<"yes"<<endl;
		return 0;
	}
	h.clear();
	c=rebuild(a);fail=0;
	a1=b;
	random_s(c);
	random_s(a1);
	for (int i=0;i<m;i++){
		for (int j=0;j<c.size();j++){
			if (push(i,j)){
				fail=1;
				break;
			}
		}
		if (fail)break;
	}
	printf(fail?"nO":"yEs");
}