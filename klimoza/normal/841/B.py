n = int(input())
a = list(map(int, input().split()))
if sum(a) % 2 == 1:
    print("First")
else:
    ch = 0
    nch = 0
    for i in a:
        if i % 2 == 0:
            ch += 1
        else:
            nch += 1
    if nch != 0:
        print("First")
    else:
        print("Second")