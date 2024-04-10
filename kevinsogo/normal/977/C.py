n, k = map(int, raw_input().split())
a = map(int, raw_input().split())
cand = [1, sorted(a)[k-1]]
cand = [i for j in cand for i in xrange(j-2,j+3) if 1 <= i <= 10**9]
for i in cand:
    if sum(b <= i for b in a) == k:
        print i
        break
else:
    print -1