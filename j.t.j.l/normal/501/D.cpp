#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int a[MAXN], c[MAXN];
int n;

int query(int x){
	int cnt = 0;
	for(; x; x -= x & -x)
		cnt += c[x];
	return cnt;
}

void insert(int x, int p){
	if (x == 0) return ;
	for(; x <= n; x += x & -x)
		c[x] += p;
}

int findrank(int p){
//	cout<<"&&&&&&&&&& "<<p<<endl;
	int l = 0, r = n, m;
//	for(int i = 1; i <= n; i++)
//		cout<<c[i]<<' '; cout<<endl;
	while(l + 1 < r){
		m = l + r >> 1;
//		cout<<l<<' '<<m<<' '<<r<<endl;
		if (query(m) >= p)
			r = m;
		else
			l = m;
	} 
	return r;
//	cout<<"&&&&&&&&&& "<<p<<endl;
}

int main(){
	cin>>n;
	for(int i = 1; i <= n; i++)
		c[i] = 0;
	for(int i = 1; i <= n; i++)
		insert(i, 1);
	for(int i = n - 1; i >= 0; i--){
		int x;
		scanf("%d", &x);
		a[i] = query(x);
		x++;
		insert(x, -1);
	}
	
//	for(int i = n-1; i >= 0; i--) cout<<a[i]<<' '; cout<<endl;
	
	for(int i = 1; i <= n; i++)
		c[i] = 0;
	for(int i = 1; i <= n; i++)
		insert(i, 1);
	for(int j = n-1; j >=0 ;j--){
		int x;
		scanf("%d", &x);
		a[j] += query(x);
		x++;
		insert(x, -1);
	}
	
	
//	for(int i = n-1; i >= 0; i--) cout<<a[i]<<' '; cout<<endl;
	
	for(int i = 0; i < n; i++)
		if (a[i] > i){
			a[i] -= i + 1;
			a[i+1] ++;
		}
		
	
//	for(int i = n-1; i >= 0; i--) cout<<a[i]<<' '; cout<<endl;
		
	for(int i = 1; i <= n + 1; i++)
		c[i] = 0;
	for(int i = 1; i <= n + 1; i++)
		insert(i, 1);
	for(int i = n-1; i >= 0; i--){
		int x = findrank(a[i]+1);
		insert(x, -1);
		printf("%d%c", x - 1, " \n"[i == 0]);
	}
	return 0;
}