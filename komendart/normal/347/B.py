n = int(input())

arr = [int(i) for i in input().split()]

d = {}

equal = 0
swap = 1
for i in range(n):
    if i == arr[i]:
        equal += 1
    elif i == arr[arr[i]]:
        swap = 2

if equal == n:
    print(n)
else:
    print(equal + swap)