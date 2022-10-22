#include <set>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 6
#define Mod 1000000007
int a[Maxn+5][Maxn+5];
int add(int a,int b){
	a+=b;
	if(a>=Mod){
		a-=Mod;
	}
	return a;
}
int sub(int a,int b){
	a-=b;
	if(a<0){
		a+=Mod;
	}
	return a;
}
int mul(int a,int b){
	return (1ll*a*b)%Mod;
}
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=mul(ans,a);
		}
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int rev(int a){
	return ksm(a,Mod-2);
}
int divv(int a,int b){
	return mul(a,rev(b));
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			a[i][j]=divv(a[i][j],100);
		}
	}
	vector<pair<vector<char>,int> > sets,newSets;
	vector<char> newSet;
	sets.push_back(make_pair(vector<char>{0},1));
	for(int g=0;g<n;g++){
		newSets.clear();
		for(int mask=0;mask<(1<<n);mask++){
			int value=1;
			for(int j=0;j<n;j++){
				if(mask&(1<<j)){
					value=mul(value,a[j][g]);
				}
				else{
					value=mul(value,sub(1,a[j][g]));
				}
			}
			for(auto& np:sets){
				newSet.clear();
				for(int mask2:np.first){
					int pos=(~mask2&mask);
					while(pos){
						int now=pos&(-pos);
						newSet.push_back(mask2|now);
						pos-=now;
					}
				}
				if(newSet.empty()){
					continue;
				}
				sort(newSet.begin(),newSet.end());
				newSet.resize(unique(newSet.begin(),newSet.end())-newSet.begin());
				newSets.push_back(make_pair(newSet,mul(np.second,value)));
			}
		}
		sort(newSets.begin(),newSets.end());
		sets.clear();
		int i=0;
		while(i<(int)newSets.size()){
			int j=i;
			int sumVal=0;
			while(j<(int)newSets.size()&&newSets[j].first==newSets[i].first){
				sumVal=add(sumVal,newSets[j].second);
				j++;
			}
			sets.push_back(make_pair(newSets[i].first,sumVal));
			i=j;
		}
	}
	int ans=0;
	for(auto& np:sets){
		ans=add(ans,np.second);
	}
	cout<<ans<<endl;
	return 0;
}