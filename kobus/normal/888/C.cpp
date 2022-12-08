#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 512345
#define INF INT_MAX/2
#define MOD 1000000007

int freq[112];
bool can[112];
string s;


bool test(int tam){
	for(int i=0;i<tam;i++){
		freq[s[i]-'a']++;
	}
	for(int i=0;i<30;i++){
		if(freq[i]==0)can[i]=0;
	}

	for(int i=0;i<s.size()-tam;i++){
		freq[s[i]-'a']--;
		freq[s[i+tam]-'a']++;
		if(freq[s[i]-'a']==0)can[s[i]-'a']=0;
	}
	for(int i=0;i<30;i++){
		if(freq[i]>0 && can[i]){
			return true;
		}
	}
	return false;
}


void reset(){
	for(int i=0;i<30;i++){
		freq[i]=0;
		can[i]=1;
	}
}

int bsearch(){
	int com=1,fim=s.size(),meio,best;
	while(com<=fim){
		reset();
		meio=fim-((fim-com)/2);
		if(test(meio)){
			best=meio;
			fim=meio-1;
		}
		else com=meio+1;
	}
	return best;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>s;
	cout<<bsearch()<<endl;	

	return 0;
}