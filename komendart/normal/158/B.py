n = int(input())
array = [int(i) for i in input().split()]
one, two, three, four = [array.count(i) for i in range(1, 5)]

result = 0

result += four

result += three
one = max(0, one - three)

result += two // 2
if two % 2 == 1:
    result += 1
    one = max(0, one - 2)

result += (one + 3) // 4

print(result)