n = input()
a = sorted(map(int, raw_input().strip().split()))
prev = a[0]-1
ans = 0
for i in xrange(n):
    if prev >= a[i]:
        ans += prev - a[i] + 1
        prev += 1
    else:
        prev = a[i]

print ans