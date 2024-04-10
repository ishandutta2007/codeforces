from collections import Counter
n, k = map(int, raw_input().strip().split())
print 'YES' if max(Counter(raw_input().strip()).values()) <= k else 'NO'