#include<bits/stdc++.h>
const int MAXN=10000,MAXM=100000,MAXL=1000,MAXS=1000000;
int N,M;
char a[MAXN+5];
std::string s[MAXM+5];
int dp[MAXN+5];
int Stack[MAXN+5],Top;
template<class T>const T&min(const T&a,const T&b){
	return a<b?a:b;
}
namespace Trie{
	const int ALPHABET_SIZE=26;
	typedef struct Trie_Node{
		Trie_Node*Next[ALPHABET_SIZE];
		int End;
	}Node;
	int Tot_Node;
	Node Node_Pool[MAXS+5];
	Node*Root;
	Node*New_Node(){
		return Node_Pool+Tot_Node++;
	}
	void Init(){
		Root=New_Node();
	}
	int Id(char a){
		return isupper(a)?a-'A':a-'a';
	}
	void Insert(int x){
		Node*P=Root;
		for(int i=0;i<s[x].length();++i){
			if(!P->Next[Id(s[x][i])])
				P->Next[Id(s[x][i])]=New_Node();
			P=P->Next[Id(s[x][i])];
		}
		P->End=x;
	}
}
using namespace Trie;
int main(){
	Init();
	scanf("%d",&N);
	scanf("%s",a+1);
	scanf("%d",&M);
	for(int i=1;i<=M;++i){
		std::cin>>s[i];
		Insert(i);
	}
	dp[0]=-1;
	for(int i=1;i<=N;++i){
		Node*P=Root;
		for(int j=1;j<=min(i,MAXL);++j){
			if(!P->Next[Id(a[i-j+1])])
				break;
			P=P->Next[Id(a[i-j+1])];
			if(dp[i-j]&&P->End){
				dp[i]=P->End;
				break;
			}
		}
	}
	for(int i=N;i;i=i-s[dp[i]].length())
		Stack[++Top]=dp[i];
	while(Top)
		std::cout<<s[Stack[Top--]]<<' ';
	return 0;
}