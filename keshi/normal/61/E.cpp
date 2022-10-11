#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 100;

#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
#define pb push_back

ll n, L[MAXN], R[MAXN], ans;
pll a[MAXN], b[MAXN], c[MAXN];

void merge(ll l, ll r){
	ll m = (l + r) / 2, s1, s2;
	ll h = m, s = 0;
	m++;
	s1 = l;
	s2 = m;
	while(l <= h && m <= r){
		if(a[l].F >= a[m].F){
			b[s++] = {a[m].F, a[m].S};
			L[a[m].S] += h - l + 1;
			m++;
		}
		else{
			b[s++] = {a[l].F, a[l].S};
			l++;
		}
	}
	while(m <= r){
		b[s++] = {a[m].F, a[m].S};
		m++;
	}
	while(l <= h){
		b[s++] = {a[l].F, a[l].S};
		l++;
	}
	for(ll i = 0; i < s; i++){
		a[s1 + i] = {b[i].F, b[i].S};
	}
	return;
}

void merge_sort(ll l, ll r){
	if(l == r){
		return;
	}
	ll m = (l + r) / 2;
	merge_sort(l, m);
	merge_sort(m + 1, r);
	merge(l, r);
	return;
}

void merge2(ll l, ll r){
	ll m = (l + r) / 2, s1, s2;
	ll h = m, s = 0;
	m++;
	s1 = l;
	s2 = m;
	while(l <= h && m <= r){
		if(c[l].F >= c[m].F){
			b[s++] = {c[l].F, c[l].S};
			R[c[l].S] += r - m + 1;
			l++;
		}
		else{
			b[s++] = {c[m].F, c[m].S};
			m++;
		}
	}
	while(m <= r){
		b[s++] = {c[m].F, c[m].S};
		m++;
	}
	while(l <= h){
		b[s++] = {c[l].F, c[l].S};
		l++;
	}
	for(ll i = 0; i < s; i++){
		c[s1 + i] = {b[i].F, b[i].S};
	}
	return;
}

void merge_sort2(ll l, ll r){
	if(l == r){
		return;
	}
	ll m = (l + r) / 2;
	merge_sort2(l, m);
	merge_sort2(m + 1, r);
	merge2(l, r);
	return;
}

int main(){
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i].F;
		c[i].F = a[i].F;
		c[i].S = i;
		a[i].S = i;
	}
	
	merge_sort(0, n - 1);
	merge_sort2(0, n - 1);
	
	for(ll i = 0; i < n; i++){
		ans += R[i] * L[i];
	}
	
	cout << ans;
	
	return 0;
}