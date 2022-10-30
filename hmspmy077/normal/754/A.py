n = input()
a = map(int, raw_input().split())
if sum(a) != 0:
    print 'YES'
    print 1
    print 1, n
else:
    if all(x == 0 for x in a):
        print 'NO'
    else:
        i = 1
        while a[i - 1] == 0:
            i += 1
        print 'YES'
        print 2
        print 1, i
        print i + 1, n