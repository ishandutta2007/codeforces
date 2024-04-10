#include <cstdio>
#include <map>
#include <iostream>

std::map<int,long long>map;
int n,calc[100001][27],esp[100001];
char str[100001];
long long ans;
int main(){
	scanf("%d",&n);
	for(int i=1,j;i<=n;i++){
		scanf("%s",str);
		for(j=0;str[j];j++)calc[i][str[j]-'a']++;
		for(j=0;j<26;j++)if(calc[i][j]%2)esp[i]|=1<<j;
		map[esp[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++)
			if(!(esp[i]&(1<<j))){
				ans+=map[esp[i]|(1<<j)];
			}
	}
	for(int i=1;i<=n;i++){
		if(map.count(esp[i])){
			ans+=(map[esp[i]]*(map[esp[i]]-1))>>1;
			map.erase(esp[i]);
		}
	}
	std::cout<<ans;
}