n = int(raw_input())
max = 0
number = 0
for i in xrange(n):
    a, b = [int(i) for i in raw_input().split()]
    number += b - a
    if max < number:
        max = number
print max