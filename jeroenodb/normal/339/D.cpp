#include <iostream>

using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << " "; } while(false)

int n,m;
int arr[(1<<17)+10], segtree[(1<<17)+10];
int build(int l, int r, int i, bool toxor) {
	//D(l);D(r); cout << endl;
	if(l==r-1) {
		return segtree[i] = arr[l]|arr[r];
	}
	int mid = (l+r)/2;
	if(toxor) return segtree[i] = build(l,mid,i*2, !toxor) ^ build(mid+1,r,i*2+1, !toxor);
	else return segtree[i] = build(l,mid,i*2, !toxor) | build(mid+1,r,i*2+1, !toxor);
}

void update() {
	int p,b;
	cin >> p >> b;
	--p;
	arr[p] = b;
	int i = (1<<(n-1))+p/2;
	if(p&1) p--; 
	segtree[i] = arr[p] | arr[p+1];
	i/=2;
	while(i!=0) {
		segtree[i] = segtree[i*2] ^ segtree[i*2+1];
		i/=2;
		if(i==0) break;
		segtree[i] = segtree[i*2] | segtree[i*2+1];
		i/=2;
	}
}
void printseg() {
	cout << "segtree\n";
    for(int i=0;i<n;++i) {
    	int a = 1<<i;
    	for(int j=a;j<2*a;++j) {
    		cout << segtree[j] << ' ';
    	} cout << endl;
    }
    for(int i=0;i<(1<<n);++i) cout << arr[i] << ' ';

    cout << "\n----\n";
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < (1<<n); ++i) {
    	cin >> arr[i];
    }

    build(0,(1<<n)-1,1,!(n&1));
	//printseg();
    while(m--) {
    	update();
    	//printseg();
    	cout << segtree[1] << endl;
    }
}