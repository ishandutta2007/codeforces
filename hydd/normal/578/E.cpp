#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
char s[110000]; int n,nxt[110000];
bool vis[110000]; vector<int> L,R,a,b,c;
vector<pii> LL,LR,RL,RR;
void print(vector<int> &vec){
	for (int v:vec) printf("%d ",v+1);
}
int main(){
	scanf("%s",s); n=strlen(s);
	for (int i=0;i<n;i++) vis[i]=false,nxt[i]=n;
	for (int i=0;i<n;i++){
		if (s[i]=='R'){
			if (!L.empty()) nxt[L.back()]=i,L.pop_back();
			R.push_back(i);
		} else{
			if (!R.empty()) nxt[R.back()]=i,R.pop_back();
			L.push_back(i);
		}
	}
	printf("%d\n",(int)L.size()+(int)R.size()-1);
	for (int i=0;i<n;i++){
		vis[nxt[i]]=true;
		if (vis[i]) continue;
		int x=i;
		while (nxt[x]!=n) x=nxt[x];
		pii u=pii(i,x);
		if (s[i]=='R'){
			if (s[x]=='R') RR.push_back(u);
			else RL.push_back(u);
		} else{
			if (s[x]=='R') LR.push_back(u);
			else LL.push_back(u);
		}
	}
	while (!RR.empty()&&!LL.empty()){
		nxt[RR.back().second]=LL.back().first;
		RL.push_back(pii(RR.back().first,LL.back().second));
		RR.pop_back(); LL.pop_back();
	}
	int u;
	if (!RR.empty()){
		u=RR.back().first;
		while (u!=n) c.push_back(u),u=nxt[u];
	}
	if (!LL.empty()){
		u=LL.back().first;
		while (u!=n) c.push_back(u),u=nxt[u];
	}
	//assert(RR.empty()&&LL.empty())
	while (RL.size()>1){
		nxt[RL.front().second]=RL.back().first;
		RL.front().second=RL.back().second; RL.pop_back();
	}
	while (LR.size()>1){
		nxt[LR.front().second]=LR.back().first;
		LR.front().second=LR.back().second; LR.pop_back();
	}
	
	if (!LR.empty()){
		u=LR.back().first;
		while (u!=n) a.push_back(u),u=nxt[u];
	}
	if (!RL.empty()){
		u=RL.back().first;
		while (u!=n) b.push_back(u),u=nxt[u];
	}
	if (!a.empty()&&!b.empty()){
		if (a.back()<b.back()) a.push_back(b.back()),b.pop_back();
		else b.push_back(a.back()),a.pop_back();
		if (!RR.empty()) print(c);
		print(a); print(b);
		if (!LL.empty()) print(c);
	} else
		if (!a.empty()){
			if (!RR.empty()) print(c);
			print(a);
			if (!LL.empty()) print(c);
		} else
			if (!b.empty()){
				if (!LL.empty()) print(c);
				print(b);
				if (!RR.empty()) print(c);
			} else print(c);
	return 0;
}