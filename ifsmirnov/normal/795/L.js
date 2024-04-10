var n, k
s1 = readline().split(' ')
n = 1*s1[0]
k = 1*s1[1]
s = readline()

var l = 0
var r = n
var Fail = 0
for (var i = 0; i < n; ++i) {
    if (s[i] == '1') {
        Fail = 1
    }
}
if (Fail == 0 && k == n) {
    print(0)
} else {
while (l + 1 < r) {
    var m = Math.floor((l + r) / 2)
    
    var rem = k
    var last = 0
    var prev = -1
    var fail = 0
    for (var i = 0; i < n; ++i) {
        if (s[i] == '0') {
            prev = i
        }
        if (i == 0 || i == last + m || i == n-1) {
            if (prev == -1) {
                fail = 1
                break
            }
            
            last = prev
            --rem
            prev = -1
        }
    }
   
    if (fail == 1 || rem < 0) {
        l = m
    } else {
        r = m
    }
}
print(r-1)
}