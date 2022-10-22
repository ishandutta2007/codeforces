main() {
	long long n; int t;
	for (scanf("%d", &t); t --; ) {
		scanf("%lld", &n);
		printf("%lld %lld\n", 1 - n, n);
	}
}