#include<bits/stdc++.h>
using namespace std;

int n, k;

char a[200005];
bool on[200005];

vector<int> st;
vector<pair<int,int> > mat;

int main()
{
	scanf("%d%d%s",&n,&k,a);
	for(int i=0;i<n;i++) {
		if(a[i] == '(') st.push_back(i);
		else {
			if(!st.empty()) {
				int I = st.back();
				st.pop_back();
				mat.push_back({I, i});
			}
		}
	}
	sort(mat.begin(), mat.end());
	for(int i=(n-k)/2;i<n/2;i++) {
		on[mat[i].first] = true;
		on[mat[i].second] = true;
	}
	for(int i=0;i<n;i++) {
		if(on[i]) printf("%c",a[i]);
	}
}