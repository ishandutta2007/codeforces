#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
using lint = long long;
using pi = pair<int, int>;
int n;
struct rect{
	int sx, ex, sy, ey, idx;
}a[MAXN];
 
auto cmp1 = [](const rect &a, const rect &b){
	if(a.sx != b.sx) return a.sx < b.sx;
	if(a.ex != b.ex) return a.ex < b.ex;
	return a.idx < b.idx;
};
auto cmp2 = [](const rect &a, const rect &b){
	if(a.ex != b.ex) return a.ex > b.ex;
	if(a.sx != b.sx) return a.sx > b.sx;
	return a.idx > b.idx;
};
auto cmp3 = [](const rect &a, const rect &b){
	if(a.sy != b.sy) return a.sy < b.sy;
	if(a.ey != b.ey) return a.ey < b.ey;
	return a.idx < b.idx;
};
auto cmp4 = [](const rect &a, const rect &b){
	if(a.ey != b.ey) return a.ey > b.ey;
	if(a.sy != b.sy) return a.sy > b.sy;
	return a.idx > b.idx;
};
 
bool dfs(
set<rect, decltype(cmp1)> &s0, 
set<rect, decltype(cmp2)> &s1, 
set<rect, decltype(cmp3)> &s2, 
set<rect, decltype(cmp4)> &s3
){
	if(s0.size() == 1) return true;
	auto itr0 = s0.begin(); int arg0 = -1e9;
	auto itr1 = s1.begin(); int arg1 = 2e9;
	auto itr2 = s2.begin(); int arg2 = -1e9;
	auto itr3 = s3.begin(); int arg3 = 2e9;
	for(int i = 0; i + 1 < s0.size(); i++){
		arg0 = max(arg0, itr0->ex);
		arg1 = min(arg1, itr1->sx);
		arg2 = max(arg2, itr2->ey);
		arg3 = min(arg3, itr3->sy);
		itr0++; itr1++; itr2++; itr3++;
		vector<rect> split;
		if(arg0 <= itr0->sx){
			itr0 = s0.begin();
			for(int j = 0; j <= i; j++) split.push_back(*itr0++);
		}
		else if(arg1 >= itr1->ex){
			itr1 = s1.begin();
			for(int j = 0; j <= i; j++) split.push_back(*itr1++);
		}
		else if(arg2 <= itr2->sy){
			itr2 = s2.begin();
			for(int j = 0; j <= i; j++) split.push_back(*itr2++);
		}
		else if(arg3 >= itr3->ey){
			itr3 = s3.begin();
			for(int j = 0; j <= i; j++) split.push_back(*itr3++);
		}
		if(split.size()){
			set<rect, decltype(cmp1)> ss0(cmp1);
			set<rect, decltype(cmp2)> ss1(cmp2);
			set<rect, decltype(cmp3)> ss2(cmp3);
			set<rect, decltype(cmp4)> ss3(cmp4);
			for(auto &i : split){
				ss0.insert(i); ss1.insert(i); ss2.insert(i); ss3.insert(i);
				s0.erase(i); s1.erase(i); s2.erase(i); s3.erase(i);
			}
			return dfs(s0, s1, s2, s3) && dfs(ss0, ss1, ss2, ss3);
		}
	}
	return false;
}
 
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		a[i].idx = i;
		scanf("%d %d %d %d",&a[i].sx,&a[i].sy,&a[i].ex,&a[i].ey);
	}
	set<rect, decltype(cmp1)> s1(cmp1);
	set<rect, decltype(cmp2)> s2(cmp2);
	set<rect, decltype(cmp3)> s3(cmp3);
	set<rect, decltype(cmp4)> s4(cmp4);
	for(int i=0; i<n; i++){
		s1.insert(a[i]);
		s2.insert(a[i]);
		s3.insert(a[i]);
		s4.insert(a[i]);
	}
	puts(dfs(s1, s2, s3, s4) ? "YES" : "NO");
}