input()
a = [int(i) for i in input().split()]
b_min = min(int(i) for i in input().split())

TL = max(2 * min(a), max(a))
if TL < b_min:
    print(TL)
else:
    print(-1)