n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr1 = list(map(int, input().split()))
s = set()
for elem in arr1:
    s.add(elem)
for elem in arr:
    if elem in s:
        print(elem, end=' ')