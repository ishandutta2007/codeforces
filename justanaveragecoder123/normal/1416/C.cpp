#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cassert>
#include<cassert>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<numeric>
#include<random>
#include<chrono>
#include<bitset>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define sz(x) (int)(x).size()
#define gc getchar
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mp make_pair

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double PI=acos(-1);
const ll INF = 1LL<<62;
const ll MINF = -(1LL<<62);

template<typename T> T getint() {
	T val=0;
	char c;
	
	bool neg=false;
	while((c=gc()) && !(c>='0' && c<='9')) {
		neg|=c=='-';
	}

	do {
		val=(val*10)+c-'0';
	} while((c=gc()) && (c>='0' && c<='9'));

	return val*(neg?-1:1);
}

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); uniform_int_distribution<int>(0, n-1)(rng)

//https://gist.github.com/KupynOrest/82d8ff09c9340c57721a05387b0a948a
long long merge (int *arr, int left, int middle, int right) {
    int *temp = new int[right - left];
    memcpy(temp, arr + left, (right - left) * sizeof(int));
   
    int i1 = 0;
    int i2 = (right - left) / 2;
    long long inversions = 0;
    for (int i = 0; i < right - left; i++) {
        if ((i1 < (right - left) / 2) && (temp[i1] <= temp[i2] || i2 >= (right - left))) {
            arr[left + i] = temp[i1++];
        } else {
            arr[left + i] = temp[i2++];
            inversions += (right - left) / 2 - i1;
        }
    }
    delete temp;
    return inversions;
}

long long mergeSort(int *arr, int left, int right) {
    long long countA, countB, countC;
    countA = countB = countC = 0;
    if (right - left > 1) {
        int middle = left + (right-left)/2;
        
        countA = mergeSort(arr, left, middle);
        countB = mergeSort(arr, middle, right);
        
        countC = merge(arr, left, middle, right);
    }
    return countA + countB + countC;
}

long long sortCount(int *arr, int n) {
    if (n == 1) {
        return 0;
    } else {
        return mergeSort(arr, 0, n);
    }
}

ll sortCount(vector<int> arr) {
	int *ar=new int[sz(arr)];
	for(int i=0;i<sz(arr);++i) {
		ar[i]=arr[i];
	}
	ll res=sortCount(ar, sz(arr));
	delete ar;
	return res;
}


int main() {
	IO;
	int n;
	cin>>n;
	vector<int> t(n);
	for(int i=0;i<n;++i) {
		cin>>t[i];
	}
	
	ll alap=sortCount(t);
	ll ans=0;
	for(int i=30;i>=0;i--) {
		vector<int> cpy=t;
		for(auto& j:cpy) {
			j^=(1<<i);
		}
		ll akt=sortCount(cpy);
		if(akt<alap) {
			alap=akt;
			for(auto& j:t) j^=(1<<i);
			ans^=1<<i;
		}
	}
	
	cout<<sortCount(t)<<" "<<ans<<"\n";
	
	return 0;
}