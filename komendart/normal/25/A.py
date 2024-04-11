n = raw_input()
array = [int(i) for i in raw_input().split()]

if array[0] % 2 == array[1] % 2 or array[0] % 2 == array[2] % 2:
    mod = array[0] % 2
else:
    mod = array[1] % 2

i = 0
while i < n:
    if array[i] % 2 != mod:
        print i + 1
        break
    i += 1