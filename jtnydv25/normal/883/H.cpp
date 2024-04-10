#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";

const int N = 4e5 + 10;

int freq[105], arr[N], mid[N], lft[N], rgt[N];
char s[N];

char ans[N];

vector<int> odd;

void fill(int k, int p){
	for(int i = 0; i < p; i++){
		lft[i] = i * k, rgt[i] = (i + 1) * k - 1;

		// cerr << i << " " << lft[i] << " " << rgt[i] << endl;
	}

	/*for(int i = 0; i < 100; i++) if(freq[i]){
		cerr << i << " -> " << freq[i] << endl;
	}*/
	int curr = 0;
	for(int i = 0; ; i++){
		bool found = 0;
		for(int j = 0; j < 100; j++){
			if(freq[j]){
				ans[lft[curr]++] = j;
				ans[rgt[curr]--] = j;
				freq[j] -= 2;
				found = 1;
				break;
			}
		}
		if(!found) break;
		curr++;
		if(curr == p) curr = 0;
	}
}

void printAns(int k, int p){
	printf("%d\n", p);
	for(int i = 0; i < p; i++){
		for(int j = i * k; j < (i + 1) * k; j++){
			char c = ans[j] + '0';
			printf("%c", c);
		}
		printf(" ");
	}
}

int main(){
	int n;
	sd(n);
	scanf("%s", s);

	for(int i = 0; i < n; i++) freq[s[i] - '0']++;
	for(int i = 0; i < 100; i++) if(freq[i] & 1) odd.pb(i);

	for(int p = 1; p <= n; p++){
		if(n % p == 0){
			int k = n / p;

			if(k & 1){
				if(odd.size() <= p && ((p - odd.size() + 1) & 1)){
					int pos = 0;
					for(int i : odd){
						ans[k * pos + (k >> 1)] = i;
						freq[i] --;
						pos++;
					}

					/*for(int i = 0; i < 100; i++) if(freq[i]){
						cerr << i << " -> " << freq[i] << endl;
					}*/

					for(int i = pos; i < p; i+=2){
						for(int j = 0; j < 100; j++){
							if(freq[j]){
								ans[k * i + (k >> 1)] = ans[k * (i + 1) + (k >> 1)] = j;
								freq[j] -= 2;
								break;
							}
						}
					}
					fill(k, p);
					printAns(k, p);						
					return 0;
				}
			}

			else{
				if(odd.empty()){
					fill(k, p);
					printAns(k, p);
					return 0;
				}
			}
		}
	}
}