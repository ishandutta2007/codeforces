n = int(input())
a = [int(i) for i in input().split()]
for i in a:
    if i < 0:
        print(1, i)
        a.remove(i)
        break
neg = []
for i in a:
    if i < 0:
        neg.append(i)
        if len(neg) == 2:
            a.remove(neg[0])
            a.remove(neg[1])
            print(2, ' '.join(str(i) for i in neg))
            break
    if i > 0:
        print(1, i)
        a.remove(i)
        break

print(len(a), ' '.join(str(i) for i in a))