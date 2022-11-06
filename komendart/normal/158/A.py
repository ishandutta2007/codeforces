n, k = [int(i) for i in raw_input().split()]
points = [int(i) for i in raw_input().split()]

i = 0
while i < n and points[i] > 0 and (
       i < k or points[i] == points[k - 1]): i += 1

print i