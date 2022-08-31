n, k = map(int, raw_input().strip().split())
a = map(int, raw_input().strip().split())[::-1]
b = sorted(map(int, raw_input().strip().split()))
c = [a.pop() or b.pop() for i in xrange(n)]
print 'Yes' if c != sorted(c) else 'No'